T = int(input())

for t in range(T):
    
    n = int(input())
    
    if n <= 2:
        print(0)
        continue
    
    if n%2 == 0:
        print(int(n/2)-1)
    else:
        print(int(n/2))