def main():
    E,Y = map(int,input().split())
    if E == 0:
        if Y <= 1911:
            print("M"+str(Y-1867))
        elif Y <= 1925:
            print("T"+str(Y-1911))
        elif Y<= 1988:
            print("S"+str(Y-1925))
        else:
            print("H"+str(Y-1988))
    elif E == 1:
        print(str(1867+Y))
    elif E == 2:
        print(str(1911+Y))
    elif E == 3:
        print(str(1925+Y))
    else:
        print(str(1988+Y))

if __name__ == "__main__":
    main()