n = int(input())
 
ans = 0
A = 0
B = 0
AB = 0
for _ in range(n):
    s = input()
    ans += s.count('AB')
    
    if s[-1] == 'A' and s[0] != 'B':
        A += 1 
    if s[0] == 'B' and s[-1] != 'A':
        B += 1
    if s[-1] == 'A' and s[0] == 'B':
        AB += 1
    
ans += min(A+AB, B+AB)


if AB>0 and A+B==0:
    ans -= 1

print(ans)