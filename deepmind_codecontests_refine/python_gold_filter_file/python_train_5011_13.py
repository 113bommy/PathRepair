"""
def maxi(a,n):
    l = -100000000000
    for i in range(n):
        if a[i]>l:
            l = a[i]
            p = i
    return p+1

def mini(a,n):
    l = 100000000000
    for i in range(n):
        if a[i]<l:
            l = a[i]
            p = i
    return p+1

n,m = list(map(int,input().split()))
a = list(map(int,input().split()))
b = []
r,s = maxi(a,n),mini(a,m)
for i in range(m):
    print(r,s)
    p,q = list(map(int,input().split()))
    if r not in range(p,q+1):
        for j in range(p-1,q):
            a[j]=a[j]-1
        s = mini(a,n)
        b.append(i)
    else:
        if s not in range(p,q+1):
            continue
        else:
            for j in range(p-1,q):
                a[j]=a[j]-1
            s = mini(a,n)
            r = maxi(a,n)
            b.append(i)
    print(a)
print(a[r-1]-a[s-1])
print(len(b))
print(*b)
"""


n = int(input())
a = list(input())
i = 0
l = 0
while i<n-1:
    if a[i]!=a[i+1]:
        i+=1
    else:
        j = i
        p = 0
        while j<n:
            if a[j]==a[i]:
                p=p+1
                j+=1
            else:
                break
            
        if j==n:
            if a[i]=="R":
                k = i
                t = 0
                while k<j:
                    if t%2==1:
                        l+=1
                        a[k]="G"
                    t+=1
                    k+=1
            if a[i]=="G":
                k = i
                t = 0
                while k<j:
                    if t%2==1:
                        l+=1
                        a[k]="B"
                    t+=1
                    k+=1
            if a[i]=="B":
                k = i
                t = 0
                while k<j:
                    if t%2==1:
                        l+=1
                        a[k]="G"
                    t+=1
                    k+=1
            i = j
        else:
            if p%2==1:
                if a[i]=="R":
                    k = i
                    t = 0
                    while k<j:
                        if t%2==1:
                            l+=1
                            a[k]="G"
                        t+=1
                        k+=1
                if a[i]=="G":
                    k = i
                    t = 0
                    while k<j:
                        if t%2==1:
                            l+=1
                            a[k]="B"
                        t+=1
                        k+=1
                if a[i]=="B":
                    k = i
                    t = 0
                    while k<j:
                        if t%2==1:
                            l+=1
                            a[k]="G"
                        t+=1
                        k+=1
                i = j
            else:
                if a[i]=="R":
                    if a[j]=="B":
                        z = "G"
                    if a[j]=="G":
                        z = "B"
                if a[i]=="G":
                    if a[j]=="B":
                        z = "R"
                    if a[j]=="R":
                        z = "B"
                if a[i]=="B":
                    if a[j]=="R":
                        z = "G"
                    if a[j]=="G":
                        z = "R"
                if a[i]=="R":
                    k = i
                    t = 0
                    while k<j:
                        if t%2==1:
                            l+=1
                            a[k]=z
                        t+=1
                        k+=1
                if a[i]=="G":
                    k = i
                    t = 0
                    while k<j:
                        if t%2==1:
                            l+=1
                            a[k]=z
                        t+=1
                        k+=1
                if a[i]=="B":
                    k = i
                    t = 0
                    while k<j:
                        if t%2==1:
                            l+=1
                            a[k]=z
                        t+=1
                        k+=1
                i = j
print(l)
print("".join(a))
