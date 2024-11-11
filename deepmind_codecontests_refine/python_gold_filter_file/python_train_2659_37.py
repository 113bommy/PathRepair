def main():
    n,h = input().split(" ")
    a = input().split(" ")
    
    h = int(h)
    
    s = 0
    for e in a:
        s += 1 if int(e) <= h else 2
 
    print(s)
    
main()