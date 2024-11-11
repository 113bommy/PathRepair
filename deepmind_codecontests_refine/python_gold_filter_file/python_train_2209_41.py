t = int(input())
def main():
    s = int(input())
    ans = ((s-1)//9)*10 + (s-1)%9+1 
    print(ans)

for i in range(t):
    main()