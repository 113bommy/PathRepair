n=int(input())
S=[]
for i in range(n):
    X=[int(x) for x in input().split(" ")]
    S.append(sum(X))
x=S[0]
S.sort(reverse=True)
for i in range(n):
    if(S[i]==x):
        print(i+1)
        break
