alpha="0abcdefghijklmnopqrstuvwxyz"
t=int(input())
for _ in range(t):
    n,k=map(int,input().strip().split())
    string=""
    t=n//k
    if n%k!=0:
        string=n%k*'a'
    for i in range(1,k+1):
        string+=t*alpha[i]
    print(string)



