import sys

users = []
ans = 0

for s in sys.stdin:
    if s[0] == "+":
        users.append(s[1:])
    elif s[0] == "-":
        del users[users.index(s[1:])]
    else:
        ans += len(users)*(len(s[s.index(":")+1:])-1)
        
print(ans)