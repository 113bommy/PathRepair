import sys
input = sys.stdin.readline

def output(a,b):
    sys.stdout.write(str(a)+" "+str(b)+"\n")
    

q=int(input())

for testcases in range(q):
    b,w=map(int,input().split())

    if w>4+(b-1)*3 or b>4+(w-1)*3:
        print("NO")
        continue

    print("YES")

    if b<=w:
        for i in range(b*2):
            output(4,3+i)

        w-=b
        if w:
            output(4,2)
            w-=1

        count=0
        while w:
            if count%2==0:
                output(3,3+count//2*2)
            else:
                output(5,3+count//2*2)

            count+=1
            w-=1

    else:
        for i in range(w*2):
            output(5,3+i)

        b-=w
        if b:
            output(5,2)
            b-=1

        count=0
        while b:
            if count%2==0:
                output(4,3+count//2*2)
            else:
                output(6,3+count//2*2)

            count+=1
            b-=1
        
                
            
            

        
