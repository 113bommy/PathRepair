def main():
    W_piece = {'Q':9,'R':5,'B':3,'N':3,'P':1}
    B_piece = {'q':9,'r':5,'b':3,'n':3,'p':1}
    pieces = ['Q','R','B','K','P','q','r','b','k','p']
    W = 0
    B = 0
    lines = []
    for i in range(8):
        line = input()
        lines.append(line)
    for line in lines:
        for p in range(len(line)):
            if line[p] in W_piece:
                W += W_piece[line[p]]
            if line[p] in B_piece:
                B += B_piece[line[p]]
    if W>B:
        print("White")
    elif B>W:
        print("Black")
    else:
        print("Draw")

if __name__=="__main__":
    main()
                
