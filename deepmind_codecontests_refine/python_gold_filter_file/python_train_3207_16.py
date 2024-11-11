S = input() + "R"
#print(S)
N = len(S)-1

ans = [0]*N

num = 0
for i in range(N):
    num += 1
    if S[i+1]=="L" and S[i]=="R":
        ans[i+1] += num//2
        ans[i] += num - num//2
        num = 0
    elif S[i+1]=="R" and S[i]=="L":
        ans[i-num+1] += num - num//2
        ans[i-num] += num//2
        num = 0

print(" ".join(map(str,ans)))
