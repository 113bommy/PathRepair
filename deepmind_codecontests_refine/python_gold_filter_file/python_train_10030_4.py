def solve(x,y,z):
    if(2*z > x or 2*z > y):
        print("Second")
        return
    print("First")


x,y,z = map(int,input().split())
solve(x,y,z)
    
