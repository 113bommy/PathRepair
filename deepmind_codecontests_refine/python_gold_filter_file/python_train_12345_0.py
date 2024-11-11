def main():
        n = int(input())
        if n%2==0:
            x = n//2
            m = "1"*x
            print(int(m))
        else:
            x = (n//2)-1
            m = "7"+"1"*x
            print(int(m))





main()