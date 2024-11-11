n=int(input())
left = - 10**9 - 5
right = 10**9 + 5
for i in range(n):
    op,x,ans = input().split()
    x=int(x)
    if op == '>' and ans == 'Y':
        left = max(x+1,left)
    elif op == '>':
        right = min(x,right)
        
    if op == '<' and ans == 'Y':
        right = min(x-1,right)
    elif op == '<':
        left = max(x,left)
        
    if op == '>=' and ans == 'Y':
        left = max(x,left)
    elif op == '>=':
        right = min(x-1,right)
        
    if op == '<=' and ans == 'Y':
        right = min(x,right)
    elif op == '<=':
        left = max(x+1,left)
if right<left:
    print('Impossible')
else:
    print(left)