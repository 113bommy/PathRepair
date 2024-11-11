N=int(input())
ans=0
A=0
B=0
ab=0
for _ in range(N):
    S=input()
    ans+=S.count('AB')
    A+=S[-1]=='A'
    B+=S[0]=='B'
    ab+=(S[-1]=='A' and S[0]=='B')

if ab>0 and ab==A==B:
    ans-=1
print(ans+min(A,B))