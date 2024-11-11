def op():
    start, n = map(int, input().split())

    if start%2==0:
        if n%4==3:
            return n+1+start
        if n%4==2:
            return 1+start
        if n%4==1:
            return -1*n +start
        if n%4==0:
            return start
    if n%4==3:
        return (-1*(n+1))+start
    if n%4==2:
        return start-1
    if n%4==1:
        return n+start
    if n%4==0:
        return start

for i in range(int(input())):
    print(op())