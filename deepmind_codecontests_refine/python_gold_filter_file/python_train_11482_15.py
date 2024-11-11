class Node:
    def __init__(self, gang, district):
        self.gang = gang
        self.district = district
        self.connected_districts =[]
 
    def add_district(self, gang, district):
        if self.gang == gang:
            for connected_district in self.connected_districts:
                if connected_district.add_district(gang, district):
                    return True
            return False
        self.connected_districts.append(Node(gang, district))
        return True
 
    def print_connections(self):
        for connected_district in self.connected_districts:
            print('{} {}'.format(self.district, connected_district.district))
            connected_district.print_connections()
 
test_cases = int(input())
 
for _ in range(test_cases):
    number_districts = int(input())
    districts = [(district + 1, gang) for district, gang in enumerate(map(int, input().split()))]
 
    districts = sorted(districts, key=lambda x: x[1])
    if districts[0][1] == districts[-1][1]:
        print("NO")
    else:
        print("YES")
        node = Node(districts[0][1], districts[0][0])
        node.add_district(districts[-1][1], districts[-1][0])
        if number_districts > 2:
            for district in districts[1:-1]:
                node.add_district(district[1], district[0])
        node.print_connections()