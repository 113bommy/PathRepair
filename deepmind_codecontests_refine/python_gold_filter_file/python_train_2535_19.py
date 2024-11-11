#laddder 11
#119A

'''
def main():
    from sys import stdin, stdout
    a=[0,1,1]
    for _ in range(43):
        a.append(a[-1]+a[-2])
    #print(a)
    #print(len(a))
    #print(a[-1])

    n = int(stdin.readline())
    if n==0:
        print(0,0,0)
        return
    fp = 0
    sp = 45
    while fp<sp:
        if a[fp]+a[sp] == n:
            break
        elif a[fp]+a[sp] < n:
            fp+=1
        elif a[fp]+a[sp] > n:
            sp-=1

    if a[fp]+a[sp]==n:
        stdout.write(str(a[fp])+' '+str(a[sp-2])+' '+str(a[sp-1])+'\n')
    else:
        stdout.write("I'm too stupid to solve this problem\n")

if __name__=='__main__':
    main()
'''

#320A
'''
def main():
    from sys import stdin,stdout

    state = [
                [-1,1,-1,-1,-1,-1,-1,-1,-1,-1],
                [-1,1,-1,-1,2,-1,-1,-1,-1,-1],
                [-1,1,-1,-1,3,-1,-1,-1,-1,-1],
                [-1,1,-1,-1,-1,-1,-1,-1,-1,-1],
                [-1,-1,-1,-1,-1,-1,-1,-1,-1,-1],
                [-1,-1,-1,-1,-1,-1,-1,-1,-1,-1],
                [-1,-1,-1,-1,-1,-1,-1,-1,-1,-1],
                [-1,-1,-1,-1,-1,-1,-1,-1,-1,-1],
                [-1,-1,-1,-1,-1,-1,-1,-1,-1,-1],
                [-1,-1,-1,-1,-1,-1,-1,-1,-1,-1],
            ]

    number = [int(x) for x in list(stdin.readline().strip())]
    #print(number)
    curr = 0;
    for i in number:
        #print(i,curr,state[curr][i])
        
        curr = state[curr][i]
        if curr == -1:
            break
    if curr == -1:
        stdout.write('NO\n')
    else:
        stdout.write('YES\n')


if __name__=='__main__':
    main()
'''

#43A
'''
def main():
    from sys import stdin, stdout
    import collections
    
    c = collections.Counter()
    for _ in range(int(stdin.readline())):
        c[stdin.readline().strip()]+=1
    print(c.most_common()[0][0])

if __name__=='__main__':
    main()
'''

#215A
'''
def main():
    from sys import stdin, stdout
    n = int(stdin.readline())
    a = list(map(int,stdin.readline().split()))
    m = int(stdin.readline())
    b = list(map(int,stdin.readline().split()))
    
    ans = {}
    for i in b:
        for j in a:
            if i%j==0:
                if i//j in ans:
                    ans[i//j]+=1
                else:
                    ans[i//j]=1

    stdout.write(str(ans[max(ans.keys())])+'\n')


if __name__=='__main__':
    main()
'''

#214A
'''
def main():
    from sys import stdin, stdout
    mysqr = [x*x for x in range(101)]
    #print(mysqr)
    n, m = map(int,stdin.readline().split())
    #print(n,m)

    n,m = max(n,m) , min(n,m)

    ans = 0
    for a,asqr in enumerate(mysqr):
        if asqr > n:
            break
        else:
            b = n-asqr
            if b*b + a == m:
                ans+=1
    stdout.write(str(ans)+'\n')


if __name__=='__main__':
    main()
'''

#219A
'''
def main():
    from sys import stdin,stdout
    stdin.readline()
    a = [0 for _ in range(30)]
    for x in stdin.readline().strip():
        a[ord(x)-ord('a')]+=1
    if len(set(a)) >2:
        stdout.write('-1\n')
    else:
        temp =''
        for i in range(30):
            if a[i]:
                temp += chr(ord('a')+i)
        stdout.write(temp*a[0]+'\n')
            

if __name__=='__main__':
    main()
'''

#124A
'''
def main():
    from sys import stdin, stdout
    n,a,b = map(int,stdin.readline().split())
    stdout.write(str(n-max(n-b,a+1)+1)+'\n')

if __name__=='__main__':
    main()
'''

#221A
def main():
    from sys import stdin, stdout
    n = int(stdin.readline())
    arr = [x for x in range(1,n+1)]
    arr = [arr[-1]] + arr[:n-1]
    for x in arr:
        stdout.write(str(x)+' ')
if __name__=='__main__':
    main()
