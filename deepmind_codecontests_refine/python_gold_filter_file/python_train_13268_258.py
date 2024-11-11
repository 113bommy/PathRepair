def main():
    inp = int(input())
    c = 0 
    for i in range(inp):
        inp2 = input().split()
        c += 1 if int(inp2[1])>=(int(inp2[0])+2) else 0
    print(c)
if __name__ == "__main__" : main()