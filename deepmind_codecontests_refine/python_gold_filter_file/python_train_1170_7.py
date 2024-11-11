from sys import stdin, stdout

def find(arr,N,M,X,Y):
    if 2*X<=Y:
        return sum([x.count('.') for x in arr]*X)
    r=0
    for i in arr:
        j=0
        while(j<len(i)):
            if i[j]=='*': j+=1; continue
            if j<len(i)-1 and i[j+1]==".":
                r+=Y
                j+=2
            else: 
                r+=X; j+=1
    return r


def main():
    for _ in range(int(stdin.readline())):
        N,M,X,Y=list(map(int, stdin.readline().split()))
        arr=[]
        for __ in range(N):
            arr.append(stdin.readline().strip())
        print(find(arr,N,M,X,Y))
main()