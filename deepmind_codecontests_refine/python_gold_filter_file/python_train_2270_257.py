x,y = map(int,input().split())
s=list(input())
s[y-1]=s[y-1].lower()
print(''.join(s))