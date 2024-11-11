def multi (n,x):
    cell = 0
    i = 1
    while i <= n and i <= x :
        if x%i == 0:
            r = x//i
            if r <= n:
                cell+=1
        i += 1

    return cell

n,x = list(map(int,input().split()))
print (multi(n,x))
