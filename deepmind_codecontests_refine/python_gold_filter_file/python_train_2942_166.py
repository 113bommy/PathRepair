def main():
    t = int(input())
    for i in range(t):
        n = int(input())
        if n==1:
            print(1)
        else:
            print((n-1)//2+1)

main()