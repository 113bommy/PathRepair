n=int(input())
p=list(map(int,input().split()))
valid=True
for i in range(n):
    s=input()
    num=0
    for c in s:
        if c=='a' or c=='e' or c=='i' \
                or c=='o' or c=='u' or c=='y':
            num+=1
    if num!=p[i]:
        valid=False
print('YES' if valid else 'NO')
