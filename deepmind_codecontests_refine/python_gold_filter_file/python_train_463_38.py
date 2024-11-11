from math import sqrt,ceil
def main():
    r,x,y,X,Y = map(int,input().split())
    d = sqrt((x-X)**2+(y-Y)**2)
    print(ceil(d/(2*r)))
if __name__ == '__main__':
    main()
