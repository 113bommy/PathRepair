n=int(input())
for i in range(n):
    a, b = map(int, input().split())
    s=[]
    s=list(chr((i+97))*(a//b) for i in range(b))
    if((a/b)!= round(a/b)):
        s.append(chr(b+96)*(a%b))
    print(''.join(s))
