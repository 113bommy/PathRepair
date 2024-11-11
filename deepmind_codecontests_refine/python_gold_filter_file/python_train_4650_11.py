n,k1,k2 = map(int,input().split())
ai = list(map(int,input().split()))
bi = list(map(int,input().split()))
ci = [0]*n
k = k1 + k2
for i in range(n):
    ci[i] = abs(ai[i]-bi[i])
ci.sort()
ci2 = [0]*n
ci3 = [0]*n
ci2[0] = ci[0]
ci3[0] = 1
j = 0
for i in range(1,n):
    if ci[i] == ci[i-1]:
        ci3[j] += 1
    else:
        j += 1
        ci2[j] = ci[i]
        ci3[j] = 1
temp2 = -1
temp3 = 0
for i in range(j,0,-1):
    if k  >= ci3[i] * (ci2[i]-ci2[i-1]):
        k -= ci3[i] * (ci2[i]-ci2[i-1])
        ci3[i-1] += ci3[i]  
        ci3[i] = 0
    else:
        temp = k // ci3[i]
        temp2 = k % ci3[i]
        temp3 = i
        ci2[i] -= temp
        break
if temp2 != -1:
    ans = 0
    for i in range(temp3):
        ans += ci3[i]*(ci2[i]**2)
    print(ans+(ci3[temp3]-temp2)*(ci2[temp3]**2) + temp2*((ci2[temp3]-1))**2)
else:
    if k >= ci3[0] * ci2[0]:
        k -= ci3[0] * ci2[0]
        print(k%2)
    else:
        temp = k // ci3[0]
        temp2 = k % ci3[0]
        print((ci3[0]-temp2)*((ci2[0]-temp)**2) + temp2*((ci2[0]-temp-1))**2)
    
