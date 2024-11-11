def solve(a : list)->str:
    r, g, b = a[0], a[1], a[2]
    if(r==0 and g==0)or(r==1 and g==1 and b==0):
        return "B"
    elif(r==0 and b==0)or(r==1 and g==0 and b==1):
        return "G"
    elif(b==0 and g==0)or(r==0 and g==1 and b==1):
        return "R"
    elif(r==0 and g==1):
            return "GR"
    elif(r==0 and b==1):
            return "BR"
    elif(g==0 and b==1):
            return "BG"
    elif(g==0 and r==1):
            return "GR"
    elif(b==0 and g==1):
            return "BG"
    elif(b==0 and r==1):
            return "BR"
    else:
        return "BGR"
def main():
    n = int(input())
    s = input()
    a = [s.count("R"), s.count("G"), s.count("B")]
    print(solve(a))
main()
