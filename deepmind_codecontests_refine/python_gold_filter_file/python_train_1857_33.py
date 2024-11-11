input()
s=sorted(map(int,input().split()))[::-1]
print(abs(sum(s[::2])-sum(s[1::2])))