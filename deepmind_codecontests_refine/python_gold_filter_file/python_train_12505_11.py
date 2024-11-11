def main():
    x = int(input())
    if x == 1: 
        print(-1)
    elif x == 2:
        print(2, 2)
    elif x % 2 == 1:
        print(x - 1, 2)
    else:
        print(x, 2)
    

main()
