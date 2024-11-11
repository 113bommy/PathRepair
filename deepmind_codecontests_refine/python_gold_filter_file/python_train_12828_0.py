from sys import stdin

for case in range(int(stdin.readline())):
    n,x,y = [int(z) for z in stdin.readline().split()]

    if x+y < n+1:
        best = 0
    else:
        best = x+y-n

    if x+y > n:
        worst = n
    else:
        worst = x+y-1

    print(min(best+1,n), worst)

    

    
