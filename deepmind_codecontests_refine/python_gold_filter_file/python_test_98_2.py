def stri(s):
    return [char for char in s]

def solve():
    keyboard =stri(input())
    s = str(input())
    compt = 0
    for i in range(1,len(s)) :
        compt += abs( keyboard.index(s[i-1]) - keyboard.index(s[i]))
        #print(abs( keyboard.index(s[i-1])  - keyboard.index(s[i])))
    print(compt)    
    
def main():
    t = int(input())
    
    for i in range(t):
        solve()
    
    
main()