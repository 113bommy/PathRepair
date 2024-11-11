import sys

def main():

    n,k=map(int,sys.stdin.readline().strip().split())
    arr=list(map(int,sys.stdin.readline().strip().split()))
    arr.sort()
    dic={}
    for a in arr:
        if a/k not in dic:
            dic[a]=1
    
    print(len(dic))

main()