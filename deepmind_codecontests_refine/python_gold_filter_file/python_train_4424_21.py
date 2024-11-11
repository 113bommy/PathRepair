import sys
s=input()
for x in range(len(s)+1):
    for y in range(x,len(s)+1):
        if s[:x]+s[y:]=='CODEFORCES':
            print("YES")
            sys.exit(0)
print("NO")