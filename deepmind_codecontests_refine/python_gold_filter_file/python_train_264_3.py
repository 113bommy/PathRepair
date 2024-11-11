m = []
for i in range(4):
    m.append(input())

def match(r,c, r2, c2):
    if r > 3 or c > 3 or r < 0 or c < 0 or r2 > 3 or c2 > 3 or r2 < 0 or c2 < 0:
        return False
    return m[r][c] == "x" and m[r2][c2] == "x"

def check(r,c):
    if(match(r,c+1,r,c-1) or\
       match(r,c+1,r,c+2) or\
       match(r,c-1,r,c-2) or\
       match(r+1,c,r-1,c) or\
       match(r+1,c,r+2,c) or\
       match(r-1,c,r-2,c) or\
       match(r+1,c+1,r-1,c-1) or\
       match(r+1,c+1,r+2,c+2) or\
       match(r-1,c-1,r-2,c-2) or\
       match(r-1,c+1,r+1,c-1) or\
       match(r-1,c+1,r-2,c+2) or\
       match(r+1,c-1,r+2,c-2)):
        return True
    return False

def solve():
    for row in range(4):
        for column in range(4):
            if m[row][column] == ".":
                if check(row,column):
                    return "YES"
    return "NO"

print(solve())
    

                    
                     

