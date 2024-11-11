

from collections import defaultdict

def main():
    #
    # t = int(input())
    # for _ in range(t):
    n = int(input())
    #m, k = list(map(int, input().split()))
    s = input()
    r = g= b= 0
    rp = gp = bp = 0
    for i in range(n):
        if s[i] == 'R':
            r+=1
            rp = 1
        elif s[i] == 'G':
            g+=1
            gp = 1
        else:
            b+=1
            bp = 1

    score = rp+gp+bp
    total = r+g+b
    if score == 3:
        print("BGR")
    elif score == 1:
        if rp>0: print("R")
        elif gp>0: print("G")
        else: print("B")
    else:
        if rp == 0:
            if total >3:
                if g>1 and b>1:
                    print("BGR")
                elif g>1 and b == 1:
                    print("BR")
                else:
                    print("GR")
            elif total == 2:
                print("R")
            else:
                if b == 2:
                    print("GR")
                else:
                    print("BR")
        elif gp == 0:
            if total > 3:
                if r > 1 and b > 1:
                    print("BGR")
                elif r > 1 and b == 1:
                    print("BG")
                else:
                    print("GR")

            elif total == 2:
                print("G")
            else:
                if b == 2:
                    print("GR")
                else:
                    print("BG")
        else:
            if total > 3:
                if r > 1 and g > 1:
                    print("BGR")
                elif r > 1 and g == 1:
                    print("BG")
                else:
                    print("BR")

            elif total == 2:
                print("B")
            else:
                if g == 2:
                    print("BR")
                else:
                    print("BG")


if __name__ == "__main__":
    main()