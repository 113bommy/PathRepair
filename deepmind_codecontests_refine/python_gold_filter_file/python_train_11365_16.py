n = int(input())
s = input()
ans = int(s)
i = n//2
j = n//2 + 1
while(s[i] == '0'):
    i -= 1
while(j < n and s[j] == '0'):
    j += 1
ans = int(s);
#print(i,j)
if(i > 0) :
    ans = min(int(s[0:i])+int(s[i:n]),ans)
if(j < n) :
    ans = min(int(s[0:j]) + int(s[j:n]),ans)
print(ans)
