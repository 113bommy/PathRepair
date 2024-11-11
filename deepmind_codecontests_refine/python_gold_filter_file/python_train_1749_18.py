N,K=list(map(int,input().split()))
S=input()
cnt=0

for i in range(N-1):
    if S[i]==S[i+1]:
        cnt+=1
print(min(cnt+K*2,N-1))