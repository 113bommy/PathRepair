n, k = [int(b) for b in input(). split()]
a = input().split()
q, mas = 1, [1]
if n == 1:
    print(1)
elif n==2:
    if a[0]!=a[1]:
        print(2)
    else:
        print(1)
else:
    for i in range(1, len(a)-1):
        if a[i]!=a[i-1] and a[i]!=a[i+1]:
            q+=1
        else:
            if a[i]!=a[i-1]:
                q+=1
            mas.append(q)
            q=1
    mas.append(q+1)

    print(max(mas))