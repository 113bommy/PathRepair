'''
def main():
    from sys import stdin,stdout
if __name__=='__main__':
    main()
'''
#1
def main():
    from sys import stdin,stdout
    l=[]
    flag=0
    n=int(stdin.readline())
    for _ in range(n):
        s=stdin.readline().strip()
        if 'OO' in s and flag==0:
            flag=1
            s=s.replace('OO','++',1)
        l.append(s)
    if flag:
        stdout.write('YES')
        for i in range(n):
            stdout.write('\n'+l[i])
    else:
        stdout.write('NO')
if __name__=='__main__':
    main()
