def solve():
    rows, cols=list(map(int, input().strip().split(' ')))
    perrow = cols//2
    if cols%2==1:
        count = perrow*rows
        count += (rows//2)
        if rows%2==1:
            count+=1 
        print(count)
    else:
        count=perrow*rows
        print(count)

def main():
    t = int(input())
    for _ in range(t):
        solve()

if __name__=='__main__':
    main()