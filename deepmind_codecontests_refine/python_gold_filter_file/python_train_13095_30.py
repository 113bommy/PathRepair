N=int(input())
S=input()
c=0
for i in range(N-1):
    if S[i]==S[i+1]:
        c+=1
print(N-c)