n,v = map(int,input().split())
l1 = []
l2 = []
for i in range(n):
    t,x = map(int,input().split())
    if t == 1:
        l1.append([x,i+1])
    else:
        l2.append([x,i+1])
l1.sort(reverse=True)
l2.sort(reverse=True)

s1 = [0]
s2 = [0]
for i in range(min(v,len(l1))):
    s1.append(s1[-1]+l1[i][0])
for i in range(min(int(v/2),len(l2))):
    s2.append(s2[-1]+l2[i][0])
ans = 0
num = 0
# print(s1)
# print(s2)
for i in range(min(v,len(l1))+1):
    # print(t)
    t = s1[i]+s2[min(len(l2),int((v-i)/2))]
    if ans < t:num,ans=i,t

print(ans)
for i in range(num):print(l1[i][1],end=' ')
for i in range(min(len(l2),int((v-num)/2))):print(l2[i][1],end=' ')