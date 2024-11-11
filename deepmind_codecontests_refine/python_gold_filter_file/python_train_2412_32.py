from sys import stdin,stdout
def main():
    read,write,i,st,pr=stdin.readline,stdout.write,int,str,print
    n=i(read())
    val=other(n)
    if not val:
        write('NO\n')
    else:
        pr(val[0],val[1])
def other(n):
    if n%2==0 or (n-3)//2<=0:
        return 0
    return (1,(n-3)//2)
if __name__=='__main__':
    main()
