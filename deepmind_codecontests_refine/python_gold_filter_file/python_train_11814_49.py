from sys import stdin
def main():
    a=stdin.readline().strip()
    while a!='':
        b,c=a.split()
        b,c=int(b),int(c)
        d=b*c
        cont=0
        while(d>1):
            cont+=1
            d=d-2
        print(cont)
        a=stdin.readline().strip()
main()
