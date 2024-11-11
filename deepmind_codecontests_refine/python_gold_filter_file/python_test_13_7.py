x = int(input())
while True:
    p = input()
    q = 0
    r = 0
    for j in p:
        if j == 'C' or j == 'A':
            q=q+1
        else:
            r=r+1
    if q == r:
        print("YES")
    else:
        print("NO")
    x=x-1
    if x>0:
        continue
    else:
        break