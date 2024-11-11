n,m = map(int,input().split())
s = list(input())
s[m-1] = s[m-1].lower()
print(''.join(s))