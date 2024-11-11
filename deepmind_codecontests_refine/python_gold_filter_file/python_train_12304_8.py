def solve(a,b):
    if a == 9 and b ==1:
        return 9,10
    elif a > b :
        return [-1]
    elif a == b:
        return b*10, b*10+1 
    elif abs(a-b) > 1 :
        return [-1]
    else:
        return b*10-1, b*10


def main():
    n = list(map(int,input().split(" ")))
    print(*solve(n[0],n[1]))

main()