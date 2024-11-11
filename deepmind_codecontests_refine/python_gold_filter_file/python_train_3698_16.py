n=int(input())
s=str(input())
if (s.count("R")==0 and s.count("B")==0) or (s.count("R")==0 and s.count("G")==0) or (s.count("B")==0 and s.count("G")==0):
    if (s.count("R")!=0):
        print("R")
    elif (s.count("B")!=0):
        print("B")
    else:
        print("G")
elif s.count("G")==0 or s.count("B")==0 or s.count("R")==0:
    if (s.count("R")==0):
        if s.count("G")==1 and s.count("B")==1: 
            print("R")
        elif s.count("G")==1 and s.count("B")!=1:
            print("GR")
        elif s.count("G")!=1 and s.count("B")==1:
            print("BR")
        else:
            print("BGR")
        
        
    elif (s.count("B")==0):
        if s.count("R")==1 and s.count("G")==1: 
            print("B")
        elif s.count("R")==1 and s.count("G")!=1:
            print("BR")
        elif s.count("R")!=1 and s.count("G")==1:
            print("BG")
        else:
            print("BGR")
        


    else:
        if s.count("R")==1 and s.count("B")==1: 
            print("G")
        elif s.count("R")==1 and s.count("B")!=1:
            print("GR")
        elif s.count("R")!=1 and s.count("B")==1:
            print("BG")
        else:
            print("BGR")
        






        

else:
    print("BGR")
