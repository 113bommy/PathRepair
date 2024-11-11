def main():
    vals = dict([(i+1, int(v)) for i,v in enumerate(input().split())])
    #print(vals)
    d = input()
    print(sum(vals[int(c)] for c in d))




if __name__ == "__main__":
    main()
