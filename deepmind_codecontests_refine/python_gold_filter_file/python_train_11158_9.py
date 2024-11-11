n = int(input())
s = input()
t = input()

perms = ['abc', 'acb', 'bac', 'bca', 'cab', 'cba']

ans = []
for cycle in perms:
    ans.append(n*cycle)
    ans.append(n*cycle[0]+n*cycle[1]+n*cycle[2])
 
for a in ans:
    for i in range(3*n - 1):
        if a[i:i+2] == s or a[i:i+2] == t:
            break

    else:
        print('YES')
        print(a)
        break
        

