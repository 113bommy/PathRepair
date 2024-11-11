def solve(n,m):
    for i in range(1, n+1):
        if i%4==2:
            for j in range(m-1):
                print('.', end = '')
            print('#')
        elif i%4==0:
            print('#', end= '')
            for k in range(m-1):
                print('.',end= '')
            print()
        else:
            for l in range(m):
                print('#', end = '')
            print()
            
if __name__ == '__main__':
    n,m = map(int, input().split())
    solve(n,m)
