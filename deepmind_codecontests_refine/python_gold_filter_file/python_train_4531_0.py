import math
def main(m):
    if m == 0:
        print("0 0")
    else:
        x = math.floor(1/6*((12*m - 3)**0.5 + 3)) # Approx ?...
        while True:
            d = m - (x**3 - (x-1)**3)
            if (d < 0): x -= 1
            elif (d > x * 6 + 6): x += 1
            else: break
        s,r = divmod(d, x)
        #print("x:{}, d:{}, s:{}, r:{}".format(x,d,s,r));
        if s == 0:
            print("{} {}".format(2*x-r-1,2*r+2))
        elif s == 1:
            print("{} {}".format(x-2*r-2,2*x))
        elif s == 2:
            print("{} {}".format(-x-r-1,2*(x-r-1)))
        elif s == 3:
            print("{} {}".format(-2*x+r+1,-2*r-2))
        elif s == 4:
            print("{} {}".format(-x+2*r+2,-2*x))
        elif s == 5:
            print("{} {}".format(x+r+1,-2*x+2*r+2))
            
if __name__ == "__main__":
    main(int(input()))
