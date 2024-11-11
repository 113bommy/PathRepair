def main():
    n = int(input())
    l1 = list(map(int,input().split()))
 #   print(l1)
    if(1 in l1):
        print("HARD")
    else:
        print("EASY")

main()