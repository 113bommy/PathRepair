# Uses python3
import sys
import math

def fn(m,n,k):
    a = [[1]*n]*m
    x=[]
    y=[]
    for i in range(m):
        for j in range(n):
            if k[i][j]==0:
                a[i]=[0]*n
                x.append(j)
                continue
            else:
                y.append([i,j])
        continue
    
    y1 = [0]*len(y)
    for j in x:
        for i in range(m):
            a[i][j]=0
            

    for i in y:
        if 1 in a[i[0]]:
            y1[y.index(i)]=1
        else:
            for j in range(m):
                if a[j][i[1]]==1:
                    y1[y.index(i)]=1
                    break
        
    if 0 in y1:
        print("NO")
    else:
        print("YES")    
        print('\n'.join(['\t'.join([str(cell) for cell in row]) for row in a]))           
                

if __name__ == '__main__':    
    input = sys.stdin.read()
    data = list(map(int, input.split()))
    m=data[0]
    n = data[1]
    k = [[0]*n]*m
    l=0
    for i in range(m):
        k[i] = data[l+2:l+2+n]
        l=l+n
    fn(m,n,k)