import sys
input = sys.stdin.readline

def main():
    a = list(map(int,input().split()))
    if a[0]*a[3]*a[4] == 0:
        ans = 2*(a[0]//2+a[3]//2+a[4]//2)
    else:
        ans = max(2*(a[0]//2+a[3]//2+a[4]//2),\
            3+2*((a[0]-1)//2+(a[3]-1)//2+(a[4]-1)//2))
    print(a[1]+ans)

if __name__ == "__main__":
    main()