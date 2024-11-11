def main():
    a,b,c=map(int,input().split())
    print(max(a,b,c))

____case=0

while(True):
    try:
        #print("testcase # :",____case)
        ____case+=1
        case=1
        case=int(input())
        for __ in range(case):
            main()
        input()
        print()
    except:
        break 
