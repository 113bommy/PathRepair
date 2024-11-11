L = int(input())
for i in range(21):
    if 2**i > L:
        r = i-1
        break
        
N = r+1
ans = []
for i in range(1, N):
    ans.append([str(i), str(i+1), str(2**(i-1))])
    ans.append([str(i), str(i+1), str(0)])

t = N-1
while t >= 1:
    if L-2**(t-1) >= 2**r:
        ans.append([str(t), str(N), str(L-2**(t-1))])
        L -= 2**(t-1)
    t -= 1
        
print(N, len(ans))
for i in range(len(ans)):
    print(" ".join(ans[i]))