from sys import stdin
n = stdin.readline() 
arr = [int(x) for x in stdin.readline().split()] 
    
print(*sorted(arr))