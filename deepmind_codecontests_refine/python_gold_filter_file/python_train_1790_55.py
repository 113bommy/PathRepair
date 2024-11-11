x = int(input())
ans = []
for i in range(x):
    q = int(input())
    if q == 2:
        ans.append('2')
    elif q % 2:
        ans.append('1')
    else:
        ans.append('0')
print('\n'.join(ans))